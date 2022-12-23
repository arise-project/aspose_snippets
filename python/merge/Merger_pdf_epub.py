from Aspose.Pdf.HtmlSaveOptions import (
    AntialiasingProcessingType,
    RasterImagesSavingModes,
    PartsEmbeddingModes
)

from Aspose.Pdf import (
    HtmlSaveOptions,
    Document
)

def pdf_to_epub(self):
    pathSource1 = "../../TestData/test.pdf"
    pathSource2 = "../../TestData/Second/test.pdf"

    # read pdf file to Aspose Document
    firstDoc = Document(pathSource1)
    secondDoc = Document(pathSource2)

    # create empty pdf document
    outputDoc = Document()

    # set less memory usage with unload instead of fast performance
    outputDoc.EnableObjectUnload = True

    for page in firstDoc.Pages:
        # add page from one document to another directly
        outputDoc.Pages.Add(page)

    for page in secondDoc.Pages:
        # add page from one document to another directly
        outputDoc.Pages.Add(page)

    opt1 = HtmlSaveOptions()
    # embedd css into a page
    opt1.PartsEmbeddingMode = PartsEmbeddingModes.EmbedAllIntoHtml
    # embedd images into a page
    opt1.RasterImagesSavingMode = RasterImagesSavingModes.AsEmbeddedPartsOfPngPageBackground
    # enhance conversion of documents with backgrounds
    opt1.AntialiasingProcessing = AntialiasingProcessingType.TryCorrectResultHtml
    # use fixed layout render
    opt1.FixedLayout = True

    # save pdf to html page
    outputDoc.Save("test.html", opt1)
