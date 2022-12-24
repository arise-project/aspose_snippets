from aspose.pdf import (
    License
)

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

def set_license():
    """Sets license to fully work with Aspose.PDF"""

    license_file = "../../test.lic"

    license = License()
    license.SetLicense(license_file)

    cgm_to_pdf()
    pcl_to_pdf()
    pdf_to_pptx()
    ps_to_pdf()
    eps_to_pdf()
    pdf_to_doc()
    pdf_to_svg()
    svg_to_pdf()
    epub_to_pdf()
    pdf_to_docx()
    pdf_to_tex()
    tex_to_pdf()
    html_to_pdf()
    pdf_to_emf()
    pdf_to_text()
    xps_to_pdf()
    md_to_pdf()
    pdf_to_epub()
    pdf_to_xls()
    mht_to_pdf()
    pdf_to_pdfa()
    pdf_to_xps()


if __name__ == '__main__':
    main()