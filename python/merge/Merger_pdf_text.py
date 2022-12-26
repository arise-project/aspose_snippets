from System.IO import File
import aspose.pdf.Text import TextAbsorber
from aspose.pdf import Document


def pdf_to_text(self):
    path_source1 = "../../TestData/test.pdf"
    path_source2 = "../../TestData/Second/test.pdf"

    # read pdf file to Aspose Document
    first_doc = Document(path_source1)
    second_doc = Document(path_source2)

    # create empty pdf document
    output_doc = Document()

    # set less memory usage with unload instead of fast performance
    output_doc.enable_object_unload = True

    for page in first_doc.pages:
        # add page from one document to another directly
        output_doc.pages.add(page)

    for page in second_doc.pages:
        # add page from one document to another directly
        output_doc.pages.add(page)

    # create text absorber for extract text
    textAbsorber = TextAbsorber()
    output_doc.pages.Accept(textAbsorber)
    extractedText = textAbsorber.Text

    # save content to text file
    File.WriteAllText("test.txt", extractedText)
