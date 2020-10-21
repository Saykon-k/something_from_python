#include <stdio.h>
#include <Python.h>
#include <math.h>
static PyObject *sort_vagons(PyObject *self, PyObject *args) {
    PyObject *railways;
    double max_of_vagon;
    double  double_item1;
    double* railways_c;
    double* sorted_railways;
    double* free_space;
    double double_item2;


    if (!PyArg_ParseTuple(args,"Od",&railways, &max_of_vagon)) {
        return NULL;
    }

    double len_of_wagons = PySequence_Fast_GET_SIZE(railways);


    railways_c = (double*)malloc(len_of_wagons * sizeof(double));

    sorted_railways = (double*)malloc(len_of_wagons * sizeof(double));

    free_space = (double*)malloc(max_of_vagon * sizeof(double));

    for(int i = 0; i < max_of_vagon; i++){
      free_space[i] = 0;
    }
    int p = 0;
    for(int i = 0; i < len_of_wagons; i++){
      PyObject *item2 = PySequence_Fast_GET_ITEM(railways,i);
      double_item2 = PyFloat_AsDouble(item2);
      railways_c[i] = double_item2;
      p = railways_c[i]-1;
      free_space[p] += 1;
    }

    int l = 0;
    for(int i = max_of_vagon; i > -1; i--){
      for(int k = free_space[i]; k > 0; k--){
        sorted_railways[l] = i+1;
        l++;
      }
    }

    PyObject *tup = PyTuple_New(len_of_wagons);
       for(int i = 0; i<len_of_wagons;i++){
         PyTuple_SET_ITEM(tup, i, PyLong_FromDouble(sorted_railways[i]));
       }
       // PyObject *tup1 = PyTuple_New(len_of_wagons);
       //    for(int i = 0; i<len_of_wagons;i++){
       //      PyTuple_SET_ITEM(tup1, i, PyLong_FromDouble(sorted_railways[i]));
       //    }

    free(railways_c);
    free(sorted_railways);
    free(free_space);
    return Py_BuildValue("O", tup);
  }


static PyMethodDef vagon_methods[] = {
      {
        "sort_vagons", sort_vagons, METH_VARARGS,
        "sort_vagons"
    },
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef vagon_definition = {
    PyModuleDef_HEAD_INIT,
    "vagon",
    "Module for count complex numbers and vectors.",
    -1,
    vagon_methods
};

PyMODINIT_FUNC PyInit_vagon(void) {
    Py_Initialize();
    return PyModule_Create(&vagon_definition);
}
