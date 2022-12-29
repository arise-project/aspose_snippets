from aspose.pdf import (
    PdfFileEditor,
    Document
)


def PDF():

    pathSource = "../../TestData/test.pdf"
    pdfEditor = PdfFileEditor()
    beg = 1
    end = 1

    doc = Document(pathSource)
    end = doc.Pages.Count

    if end > 1:
        end /= 2

    pdfEditor.Extract(pathSource, beg, end, "./half.pdf")
    