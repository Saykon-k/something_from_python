from distutils.core import setup, Extension

vagon = Extension('vagon', sources = ['vagon.c'])

setup(name='vagon',
      version='0.1.0',
      description='Module for count complex numbers and vectors',
      ext_modules=[vagon])
