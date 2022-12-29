from aspose.pdf import (
    SaveFormat,
    PdfFileEditor,
    TxtLoadOptions,
    TextAbsorber,
    Document
)


def TXT():
    pathSource = "../../TestData/test.txt"
    pdfEditor = PdfFileEditor()

    doc = Document(pathSource, TxtLoadOptions())
    #save input text to pdf to file
    doc.Save("test.pdf", SaveFormat.PDF)

    pages = pdfEditor.SplitToPages("test.pdf")
    index = 1
    for ms in pages:
        page = Document(ms)
        textAbsorber = TextAbsorber()
        page.Pages.Accept(textAbsorber)
        extractedText = textAbsorber.Text
        File.WriteAllText("text_"+index+".txt", extractedText)
        index++
        