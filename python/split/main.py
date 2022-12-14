from aspose.pdf import (
    License
)

import sys
from Split_HTML import *
from Split_PDF import *
from Split_TXT import *


def main():
    set_license()
    try:
        HTML()
    except Exception as e:
        sys.stderr.write(str(e))

    try:
        PDF()
    except Exception as e:
        sys.stderr.write(str(e))

    try:
        TXT()
    except Exception as e:
        sys.stderr.write(str(e))


def set_license():
    """Sets license to fully work with Aspose.PDF"""

    license_file = "../../test.lic"

    license = License()
    license.set_license(license_file)


if __name__ == '__main__':
    main()
