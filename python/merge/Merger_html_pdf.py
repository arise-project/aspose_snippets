from aspose.pdf import (
    SaveFormat,
    HtmlLoadOptions,
    Document
)


def html_to_pdf():
    path_source1 = "../../TestData/test.html"
    path_source2 = "../../TestData/Second/test.html"

    opt1 = HtmlLoadOptions()
    # set html encoding
    opt1.input_encoding = "UTF-8"
    # render all html to single large pdf page
    opt1.is_render_to_single_page = True

    # html files can be parsed and loaded as Aspose Document
    first_doc = Document(path_source1, opt1)

    opt2 = HtmlLoadOptions()
    # set html encoding
    opt2.input_encoding = "UTF-8"
    # split html content to pdf pages
    opt2.is_render_to_single_page = False

    second_doc = Document(path_source2, opt2)

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

    # save result pdf to file
    output_doc.save("Merger_html_pdf.pdf", SaveFormat.PDF)
