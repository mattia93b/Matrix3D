# Matrix3D
3D Matrix of generic type T


The project requires the creation of a generic Matrice3D class that implements a 3-cell matrix. Each cell can be accessed by giving the coordinates of the plane (z), row (y) and column (x).


The Matrice3D class, in addition to the methods necessary for its correct use, must have the following functionalities:
 It must be possible to convert a defined Matrice3D on a U type to a Matrix3D defined on a T type. Obviously the conversion will be possible if a U type element is convertible / castable to a T type element.
 It will be possible to request and write the value of a cell at the position (z, y, x) through operator (). Ex: G (1,2,3) = G (2,2,3).
 The appropriate read and write iterators will have to be implemented.

A method must be implemented, slice that, given the value of the z plane, returns the Matrix2D containing all the cells of the requested plane. This data structure must be implemented and possess all the necessary methods for its proper functioning, including iterators.
Furthermore, a generic function must be implemented which transforms, given a Matrix3D A (on T types) and a functor F, a new Matrice3D B returns (on Q types) whose elements are obtained by applying the functor to the elements of A:
B (i, j, k) = F (A (i, j, k))
Test the class and global function on both primitive and custom types and with different predicates F.
