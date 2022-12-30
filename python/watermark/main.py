from aspose.pdf import (
    License
)

import sys
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

    try:
        add()
    except Exception as e: sys.stderr.write(str(e))

    try:
        get()
    except Exception as e: sys.stderr.write(str(e))
    
    try:
        remove()
    except Exception as e: sys.stderr.write(str(e))
    
if __name__ == '__main__':
    main()