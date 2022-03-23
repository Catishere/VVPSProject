TEMPLATE = subdirs

SUBDIRS += \
    VVPSProjectTests \
    VVPSProject

VVPSProjectTests.depends = VVPSProject
