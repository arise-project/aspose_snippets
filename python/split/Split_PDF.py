from aspose.pdf import (
    Document
)

from aspose.pdf.facades import (
    PdfFileEditor
)

def PDF():

    path_source = "../../TestData/test.pdf"
    pdf_editor = PdfFileEditor()
    beg = 1
    end = 1

    doc = Document(path_source)
    end = len(doc.pages)

    if end > 1:
        end /= 2

    pdf_editor.extract(path_source, beg, end, "pdf_half.pdf")
    