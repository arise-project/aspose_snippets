from aspose.pdf import (
    TeXSaveOptions,
    Document
)


def pdf_to_tex(self):
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

    opt1 = TeXSaveOptions()
    # save parsed artifacts, for example images to a directory
    opt1.out_directory_path = "./test"

    # save pdf to TeX document
    outputDoc.Save("test.tex", opt1)
