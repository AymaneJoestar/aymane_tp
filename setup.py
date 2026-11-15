from setuptools import setup
from pybind11.setup_helpers import Pybind11Extension, build_ext

ext_modules = [
    Pybind11Extension(
        "aymane_tp",
        [
            "src/interface.cpp",
            "src/cum_médiane.cpp",
        ],
        cxx_std=11,
    ),
]

setup(
    name="aymane_tp",
    version="0.0.1",
    author="Aymane",
    ext_modules=ext_modules,
    cmdclass={"build_ext": build_ext},
    python_requires=">=3.9",
)
