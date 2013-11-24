! WHIZARD <<Version>> <<Date>>
! 
! Copyright (C) 1999-2012 by 
!     Wolfgang Kilian <kilian@physik.uni-siegen.de>
!     Thorsten Ohl <ohl@physik.uni-wuerzburg.de>
!     Juergen Reuter <juergen.reuter@desy.de>
!     Christian Speckner <christian.speckner@physik.uni-freiburg.de>
!     with contributions by Sebastian Schmidt, Daniel Wiesler, Felix Braam
!
! WHIZARD is free software; you can redistribute it and/or modify it
! under the terms of the GNU General Public License as published by 
! the Free Software Foundation; either version 2, or (at your option)
! any later version.
!
! WHIZARD is distributed in the hope that it will be useful, but
! WITHOUT ANY WARRANTY; without even the implied warranty of
! MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
! GNU General Public License for more details.
!
! You should have received a copy of the GNU General Public License
! along with this program; if not, write to the Free Software
! Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
!
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
module kinds

  use iso_c_binding !NODEP!

  implicit none
  private
 
! Three types of precision.  double is the default, usually.
  public :: single, double, quadruple
  public :: default, quad_or_single

  integer, parameter :: single = &
       & selected_real_kind (precision(1.), range(1.))
  integer, parameter :: double = &
       & selected_real_kind (precision(1._single) + 1, range(1._single) + 1)
  integer, parameter :: quadruple = &
       & selected_real_kind (precision (1._double) + 1, range (1._double))

  integer, parameter :: default = double
  integer, parameter :: quad_or_single = single

! Their C equivalents.
  public :: c_default_float, c_default_complex

  integer, parameter :: c_default_float = c_double
  integer, parameter :: c_default_complex = c_double_complex


! Integer kinds: 8 bit, 16 bit, 32 bit, and 64 bit
! These should all be available
  public :: i8, i16, i32, i64

  integer, parameter :: i8  = selected_int_kind (2)
  integer, parameter :: i16 = selected_int_kind (4)
  integer, parameter :: i32 = selected_int_kind (9)
  integer, parameter :: i64 = selected_int_kind (18)

! This is the integer size for binary codes: 32 bit (default)
! corresponds to a 2 -> 30 process, more than sufficient.
  public :: TC

  integer, parameter :: TC = i32

end module kinds
