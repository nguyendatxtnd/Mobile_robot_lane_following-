from setuptools import find_packages, setup
import os
from glob import glob

package_name = 'obstacle_detection'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', package_name, 'YOLO'),
            glob('YOLO/*')),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='nguyendat',
    maintainer_email='nguyendat2004xtc@gmail.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    extras_require={
        'test': [
            'pytest',
        ],
    },
    entry_points={
        'console_scripts': [
        	'obstacle_detection = obstacle_detection.obstacle_detection:main'
        ],
    },
)
