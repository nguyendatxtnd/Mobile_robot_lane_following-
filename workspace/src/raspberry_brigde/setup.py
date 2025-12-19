from setuptools import find_packages, setup

package_name = 'raspberry_brigde'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
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
        	'get_image = raspberry_brigde.get_image:main',
        	'send_signal_control = raspberry_brigde.send_signal_control:main'
        ],
    },
)
