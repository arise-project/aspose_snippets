import aspose.pdf.HtmlSaveOptions as HtmlSaveOptions

from aspose.pdf import (
    HtmlSaveOptions,
    Document
)


def pdf_to_epub():
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

    opt1 = HtmlSaveOptions()
    # embed css into a page
    opt1.parts_embeding_mode = HtmlSaveOptions.PartsEmbeddingModes.EMBED_ALL_INTO_HTML
    # embed images into a page
    opt1.raster_images_saving_mode = HtmlSaveOptions.RasterImagesSavingModes.AS_embedED_PARTS_OF_PNG_PAGE_BACKGROUND
    # enhance conversion of documents with backgrounds
    opt1.antialiasing_processing = HtmlSaveOptions.AntialiasingProcessingType.TRY_CORRECT_RESULT_HTML
    # use fixed layout render
    opt1.fixed_layout = True

    # save pdf to html page
    output_doc.save("test.html", opt1)
