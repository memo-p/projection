# Projection Algorithms

This repository contains the code of several norm projection algorithms.
For each type of norm $\alpha$, the projection file should be located in `code/include/l`$\alpha$`/l`$\alpha$`.hpp`.

## Vector norm
For vector, the following norms are available:

- $\ell_{1}$ norm projection.
- $\ell_{w1}$ norm (or weighted $\ell_{1}$ norm)
- $\ell_{2}$ norm projection.


## Matrix Norm
For Matrices, the following norms are available:

- $\ell_{1,1}$ norm projection.
- $\ell_{1,\infty}$ norm projection.


## Bi-level Norms
Bilevel projections are a new type of projection that relax the euclidean property of the projection (see Perez et. al. 2024). They have some advantages such as being faster to compute and yielding better accuracy in some feature selection data-sets.

The following bi-level norms are available:

- $\ell_{1,1}$ norm projection.
- $\ell_{1,2}$ norm projection.
- $\ell_{1,\infty}$ norm projection.


## 3D multi-level norms
3D multi-level, or tri-level projection, are a generalization of the bi-level relaxation to higher dimensions.
They can be applied to tensors with shape of size 3 (such as intermediate tensor representation in CNN etc.).
The following tri-level norms are available:

- $\ell_{1,1,1}$ norm projection.
- $\ell_{1,\infty,\infty}$ norm projection.


## Pytorch Binding
A pytorch binding is proposed in the `torch_bind` directory.
In order to install it on your machine you must have a valid installation of pytorch. More information [here](https://pytorch.org/tutorials/advanced/cpp_extension.html).

To install this pytorch extension, use the command:
```
python3 setup.py install --user
```
inside of the directory, then test that the installation is working using 
```
python3 test.py 
```
If the installation is working, nothing should be displayed.
Please check the `projection.cpp` or `test.py` to see the signature of the functions.


## Related Citations

> Condat, L. (2016). Fast projection onto the simplex and the l 1 ball. Mathematical Programming, 158(1), 575-585.

> Perez, G., Barlaud, M., Fillatre, L., & Régin, J. C. (2020). A filtered bucket-clustering method for projection onto the simplex and the ℓ 1 ball. Mathematical Programming, 182(1-2), 445-464.

> Perez, G., Ament, S., Gomes, C., & Barlaud, M. (2022). Efficient projection algorithms onto the weighted ℓ1 ball. Artificial Intelligence, 306, 103683.

> Perez, G., Condat, L., Barlaud, M. (2023). Near-Linear Time Projection onto the $\ell_{1,\infty}$ Ball:
Application to Sparse Autoencoders. arXiv preprint arXiv:2307.09836

> Perez, G., Barlaud, M. (2024). Multi-level projection with exponential parallel speedup; Application to sparse auto-encoders neural networks. arXiv preprint arXiv:

Please cite this repository using :
> Perez, G., Condat, L. P., & Barlaud, M. (2023). memo-p/projection.