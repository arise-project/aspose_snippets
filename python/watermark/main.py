from aspose.pdf import (
    License
)

from Watermark_add import *
from Watermark_get import *
from Watermark_remove import *


def main():
    set_license()

def set_license():
    """Sets license to fully work with Aspose.PDF"""

    license_file = "../../test.lic"

    license = License()
    license.SetLicense(license_file)

    add()
    get()
    remove()
    
if __name__ == '__main__':
    main()