from aspose.pdf import (
    License
)

import sys
from Merger_cgm_pdf import *
from Merger_pcl_pdf import *
from Merger_pdf_pptx import *
from Merger_ps_pdf import *
from Merger_eps_pdf import *
from Merger_pdf_doc import *
from Merger_pdf_svg import *
from Merger_svg_pdf import *
from Merger_epub_pdf import *
from Merger_pdf_docx import *
from Merger_pdf_tex import *
from Merger_tex_pdf import *
from Merger_html_pdf import *
from Merger_pdf_emf import *
from Merger_pdf_text import *
from Merger_xps_pdf import *
from Merger_md_pdf import *
from Merger_pdf_epub import *
from Merger_pdf_xls import *
from Merger_mht_pdf import *
from Merger_pdf_pdfa import *
from Merger_pdf_xps import *


def main():
    set_license()

    try:
        # done
        cgm_to_pdf()
    except Exception as e:
        sys.stderr.write(str(e))

    try:
        pcl_to_pdf()
    except Exception as e:
        sys.stderr.write(str(e))

    try:
        # done
        pdf_to_pptx()
    except Exception as e:
        sys.stderr.write(str(e))

    try:
        # done
        ps_to_pdf()
    except Exception as e:
        sys.stderr.write(str(e))

    try:
        # done
        eps_to_pdf()
    except Exception as e:
        sys.stderr.write(str(e))

    try:
        pdf_to_doc()
    except Exception as e:
        sys.stderr.write(str(e))

    try:
        # done
        pdf_to_svg()
    except Exception as e:
        sys.stderr.write(str(e))

    try:
        # done
        svg_to_pdf()
    except Exception as e:
        sys.stderr.write(str(e))

    try:
        # done
        epub_to_pdf()
    except Exception as e:
        sys.stderr.write(str(e))

    try:
        pdf_to_docx()
    except Exception as e:
        sys.stderr.write(str(e))

    try:
        # done
        pdf_to_tex()
    except Exception as e:
        sys.stderr.write(str(e))

    try:
        # done
        tex_to_pdf()
    except Exception as e:
        sys.stderr.write(str(e))

    try:
        html_to_pdf()
    except Exception as e:
        sys.stderr.write(str(e))

    try:
        # done
        pdf_to_emf()
    except Exception as e:
        sys.stderr.write(str(e))

    try:
        pdf_to_text()
    except Exception as e:
        sys.stderr.write(str(e))

    try:
        # done
        xps_to_pdf()
    except Exception as e:
        sys.stderr.write(str(e))

    try:
        # done
        md_to_pdf()
    except Exception as e:
        sys.stderr.write(str(e))

    try:
        pdf_to_epub()
    except Exception as e:
        sys.stderr.write(str(e))

    try:
        pdf_to_xls()
    except Exception as e:
        sys.stderr.write(str(e))

    try:
        mht_to_pdf()
    except Exception as e:
        sys.stderr.write(str(e))

    try:
        pdf_to_pdfa()
    except Exception as e:
        sys.stderr.write(str(e))

    try:
        # done
        pdf_to_xps()
    except Exception as e:
        sys.stderr.write(str(e))

def set_license():
    """Sets license to fully work with Aspose.PDF"""

    license_file = "../../test.lic"

    license = License()
    license.set_license(license_file)

if __name__ == '__main__':
    main()