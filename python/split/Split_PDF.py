from aspose.pdf import (
    PdfFileEditor,
    Document
)


def PDF():

    path_source = "../../TestData/test.pdf"
    pdf_editor = PdfFileEditor()
    beg = 1
    end = 1

    doc = Document(path_source)
    end = doc.Pages.Count

    if end > 1:
        end /= 2

    pdf_editor.Extract(path_source, beg, end, "./half.pdf")
    