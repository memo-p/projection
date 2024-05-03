from setuptools import setup, Extension
import numpy
from torch.utils import cpp_extension

setup(name='projections',
      ext_modules=[cpp_extension.CppExtension('projections', ['projections.cpp'])],
      cmdclass={'build_ext': cpp_extension.BuildExtension}, include_dirs = ['.','../code/include'])