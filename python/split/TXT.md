from aspose.pdf import (
    SaveFormat,
    PdfFileEditor,
    TxtLoadOptions,
    TextAbsorber,
    Document
)


def TXT():
    path_source = "../../TestData/test.txt"
    pdf_editor = PdfFileEditor()

    doc = Document(path_source, TxtLoadOptions())
    # save input text to pdf to file
    doc.Save("test.pdf", SaveFormat.PDF)

    pages = pdf_editor.SplitToPages("test.pdf")
    index = 1
    for ms in pages:
        page = Document(ms)
        text_absorber = TextAbsorber()
        page.Pages.Accept(text_absorber)
        extracted_text = text_absorber.Text
        file = open("text_"+str(index)+".txt", "w+")
        file.write(extracted_text)
        index = index + 1
        