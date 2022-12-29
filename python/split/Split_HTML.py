from aspose.pdf import (
    SaveFormat,
    PdfFileEditor,
    HtmlLoadOptions,
    Document
)


def HTML():
    pathSource = "../../TestData/test.html";
    doc = Document(pathSource, HtmlLoadOptions);
    #save input html to pdf to file
    doc.Save("test.pdf", SaveFormat.PDF);

    pdfEditor = PdfFileEditor();
    #slit first page
    pdfEditor.SplitFromFirst("test.pdf", 1, "test.pdf");
    doc = Document("test.pdf");
    doc.Save("first_page.html", SaveFormat.HTML);