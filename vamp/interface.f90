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

subroutine integrate(iterations, func)
    use kinds
    use exceptions
    use tao_random_numbers
    use vamp
    use basic_fct
    implicit none
    integer, intent(in) :: iterations
    interface
        subroutine func (input)
            integer, intent(in) :: input
        end subroutine func
    end interface
    type(exception) :: exc
    type(tao_random_state) :: rng
    type(vamp_grid) :: grid
    real(kind=default), dimension(2,2) :: domain
    real(kind=default) :: integral, error, chi2
    domain(1,:) = -1.0
    domain(2,:) = 1.0
    
    call func (iterations)
    
    call tao_random_create (rng, seed=0)
    call clear_exception (exc)
    call vamp_create_grid (grid, domain, num_calls=iterations, exc=exc)
    call handle_exception (exc)
    call clear_exception (exc)
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
