from setuptools import find_packages
from setuptools import setup

setup(
    name='type_msg',
    version='0.0.0',
    packages=find_packages(
        include=('type_msg', 'type_msg.*')),
)
