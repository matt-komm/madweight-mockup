module basic_fct
    use kinds
    use vamp
    implicit none
    private
    public :: fct
    contains
    function fct (x, prc_index, weights, channel, grids) result (f_x)
        real(kind=default), dimension(:), intent(in) :: x
        integer, intent(in) :: prc_index
        real(kind=default), dimension(:), intent(in), optional :: weights
        integer, intent(in), optional :: channel
        type(vamp_grid), dimension(:), intent(in), optional :: grids
        real(kind=default) :: f_x
        f_x = exp (sin(x(1)*x(2)*10)+1)
    end function fct
end module basic_fct


module vamp_grid_type
  use kinds
  use divisions
  private
  type, public :: vamp_grid
     ! private !: forced by \texttt{use} association in interface
     type(division_t), dimension(:), pointer :: div => null ()
     real(kind=default), dimension(:,:), pointer :: map => null ()
     real(kind=default), dimension(:), pointer :: mu_x => null ()
     real(kind=default), dimension(:), pointer :: sum_mu_x => null ()
     real(kind=default), dimension(:,:), pointer :: mu_xx => null ()
     real(kind=default), dimension(:,:), pointer :: sum_mu_xx => null ()
     real(kind=default), dimension(2) :: mu
     real(kind=default) :: sum_integral, sum_weights, sum_chi2
     real(kind=default) :: calls, dv2g, jacobi
     real(kind=default) :: f_min, f_max
     real(kind=default) :: mu_gi, sum_mu_gi
     integer, dimension(:), pointer :: num_div => null ()
     integer :: num_calls, calls_per_cell
     logical :: stratified = .true.
     logical :: all_stratified = .true.
     logical :: quadrupole = .false.
     logical :: independent
     integer :: equivalent_to_ch, multiplicity
  end type vamp_grid
  
  
end module vamp_grid_type

subroutine integrate(Ndim,iterations, func)
    use kinds
    use exceptions
    use tao_random_numbers
    use vamp
    use basic_fct
    implicit none
    integer, intent(in) :: Ndim
    integer, intent(in) :: iterations
    interface
        function func (xi, prc_index, weights, channel) result (f)
            use kinds
            !use vamp_grid_type !NODEP!
            real(kind=default), dimension(:), intent(in) :: xi
            integer, intent(in) :: prc_index
            real(kind=default), dimension(:), intent(in), optional :: weights
            integer, intent(in), optional :: channel
            !type(vamp_grid), dimension(:), intent(in), optional :: grids
            real(kind=default) :: f
        end function func
    end interface
    type(exception) :: exc
    type(tao_random_state) :: rng
    type(vamp_grid) :: grid
    real(kind=default), dimension(2,Ndim) :: domain
    real(kind=default) :: integral, error, chi2
    
    real(kind=default), dimension(Ndim) :: testArray
    real(kind=default) :: res

    
    
    testArray(:)=1.5134d0
    
    
    !init integration space from -1 to 1 for all dimensions
    domain(1,:) = -1.0
    domain(2,:) = 1.0
    
    
    
    write(*,*) "Ndim",Ndim
    write(*,*) "iterations",iterations
    res = func (testArray,Ndim,testArray,iterations)
    
    call tao_random_create (rng, seed=0)
    call clear_exception (exc)
    call vamp_create_grid (grid, domain, num_calls=iterations, exc=exc)
    call handle_exception (exc)
    call clear_exception (exc)
    
    !subroutine vamp_sample_grid &
    !   (rng, g, func, prc_index, iterations, &
    !    integral, std_dev, avg_chi2, accuracy, &
    !    channel, weights, grids, exc, history)
    !type(tao_random_state), intent(inout) :: rng
    !type(vamp_grid), intent(inout) :: g
    !integer, intent(in) :: prc_index
    !integer, intent(in) :: iterations
    !real(kind=default), intent(out), optional :: integral, std_dev, avg_chi2
    !real(kind=default), intent(in), optional :: accuracy
    !integer, intent(in), optional :: channel
    !real(kind=default), dimension(:), intent(in), optional :: weights
    !type(vamp_grid), dimension(:), intent(in), optional :: grids
    !type(exception), intent(inout), optional :: exc
    !type(vamp_history), dimension(:), intent(inout), optional :: history
    !interface
    !    function func (xi, prc_index, weights, channel, grids) result (f)
    !     use kinds
    !     use vamp_grid_type !NODEP!
    !     real(kind=default), dimension(:), intent(in) :: xi
    !     integer, intent(in) :: prc_index
    !     real(kind=default), dimension(:), intent(in), optional :: weights
    !     integer, intent(in), optional :: channel
    !     type(vamp_grid), dimension(:), intent(in), optional :: grids
    !     real(kind=default) :: f
    !   end function func
    !end interface
    !character(len=*), parameter :: FN = "vamp_sample_grid"
    !real(kind=default) :: local_integral, local_std_dev, local_avg_chi2
    !integer :: iteration, ndim
    !ndim = size (g%div)

    call vamp_sample_grid (rng, grid, fct, 0, 4, integral, error, chi2, exc=exc)
    call handle_exception (exc)
    call clear_exception (exc)
    print *, "integral = ", integral, "+/-", error, " (chi^2 = ", chi2, ")"
    call vamp_discard_integral (grid, num_calls=iterations, exc=exc)
    call handle_exception (exc)
    call clear_exception (exc)
    call vamp_sample_grid (rng, grid, fct, 0, 4, integral, error, chi2, exc=exc)
    call handle_exception (exc)
    print *, "integral = ", integral, "+/-", error, " (chi^2 = ", chi2, ")"
end subroutine integrate
