from aspose.pdf import (
    PptxSaveOptions,
    Document
)

def pdf_to_pptx(self):
    pathSource1 = "../../TestData/test.pdf"
    pathSource2 = "../../TestData/Second/test.pdf"

    # read pdf file to Aspose Document
    firstDoc = Document(pathSource1)
    secondDoc = Document(pathSource2)

    outputDoc = Document()
    # set less memory usage with unload instead of fast performance
    outputDoc.enable_object_unload = True

    for page in firstDoc.Pages:
        # add page from one document to another directly
        outputDoc.Pages.Add(page)

    for page in secondDoc.Pages:
        # add page from one document to another directly
        outputDoc.Pages.Add(page)

    opt1 = PptxSaveOptions()
    # save all content on page as single image
    opt1.slides_as_images = True

    # save pdf to Microsoft PowerPoint
    outputDoc.Save("test.pptx", opt1)
