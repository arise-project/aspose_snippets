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
    outputDoc.enable_object_unload = True

    for page in firstDoc.Pages:
        # add page from one document to another directly
        outputDoc.Pages.Add(page)

    for page in secondDoc.Pages:
        # add page from one document to another directly
        outputDoc.Pages.Add(page)

    opt1 = HtmlSaveOptions()
    # embedd css into a page
    opt1.parts_embedding_mode = PartsEmbeddingModes.EMBED_ALL_INTO_HTML
    # embedd images into a page
    opt1.raster_images_saving_mode = RasterImagesSavingModes.AS_EMBEDDED_PARTS_OF_PNG_PAGE_BACKGROUND
    # enhance conversion of documents with backgrounds
    opt1.antialiasing_processing = AntialiasingProcessingType.TRY_CORRECT_RESULT_HTML
    # use fixed layout render
    opt1.fixed_layout = True

    # save pdf to html page
    outputDoc.Save("test.html", opt1)
