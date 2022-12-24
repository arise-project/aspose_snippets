from aspose.pdf import (
    SaveFormat,
    HtmlLoadOptions,
    Document
)

def html_to_pdf(self):
    pathSource1 = "../../TestData/test.html"
    pathSource2 = "../../TestData/Second/test.html"

    opt1 = HtmlLoadOptions()
    # set html encodyng
    opt1.input_encoding = "UTF-8",
    # render all html to single large pdf page
    opt1.is_render_to_single_page = True

    # html files can be parsed and loaded as Aspose Document
    firstDoc = Document(pathSource1, opt1)

    opt2 = HtmlLoadOptions()
    # set html encodyng
    opt2.input_encoding = "UTF-8",
    # split html content to pdf pages
    opt2.is_render_to_single_page = False

    secondDoc = Document(pathSource2, opt2)

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

    # save result pdf to file
    outputDoc.Save("test.pdf", SaveFormat.Pdf)
