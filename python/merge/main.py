from Aspose.Pdf import (
    License
)


def main():
    set_license()

def set_license():
    """Sets license to fully work with Aspose.PDF"""

    license_file = "../../test.lic"

    license = License()
    license.SetLicense(license_file)

if __name__ == '__main__':
    main()