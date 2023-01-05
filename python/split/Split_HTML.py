from aspose.pdf import (
    SaveFormat,
    HtmlLoadOptions,
    Document
)

from aspose.pdf.facades import (
    PdfFileEditor
)


def HTML():
    path_source = "../../TestData/test.html";
    doc = Document(path_source, HtmlLoadOptions())
    # save input html to pdf to file
    doc.save("test.pdf", SaveFormat.PDF)

    pdf_editor = PdfFileEditor()
    # slit first page
    pdf_editor.split_from_first("test.pdf", 1, "test.pdf")
    doc = Document("test.pdf")
    doc.save("html_first.html", SaveFormat.HTML)
