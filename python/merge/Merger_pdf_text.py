from System.IO import File
import aspose.pdf.Text import TextAbsorber
from aspose.pdf import Document


def pdf_to_text(self):
    pathSource1 = "../../TestData/test.pdf"
    pathSource2 = "../../TestData/Second/test.pdf"

    # read pdf file to Aspose Document
    firstDoc = Document(pathSource1)
    secondDoc = Document(pathSource2)

    # create empty pdf document
    outputDoc = Document()

    # set less memory usage with unload instead of fast performance
    outputDoc.enable_object_unload = True

    for page in firstDoc.Pages:
        # add page from one document to another directly
        outputDoc.Pages.Add(page)

    for page in secondDoc.Pages:
        # add page from one document to another directly
        outputDoc.Pages.Add(page)

    # create text absorber for extract text
    textAbsorber = TextAbsorber()
    outputDoc.Pages.Accept(textAbsorber)
    extractedText = textAbsorber.Text

    # save content to text file
    File.WriteAllText("test.txt", extractedText)
