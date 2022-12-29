from aspose.pdf import (
    SaveFormat,
    PdfFileEditor,
    HtmlLoadOptions,
    Document
)


def HTML():
    path_source = "../../TestData/test.html";
    doc = Document(path_source, HtmlLoadOptions);
    # save input html to pdf to file
    doc.Save("test.pdf", SaveFormat.PDF);

    pdf_editor = PdfFileEditor();
    # slit first page
    pdf_editor.SplitFromFirst("test.pdf", 1, "test.pdf");
    doc = Document("test.pdf");
    doc.Save("first_page.html", SaveFormat.HTML);