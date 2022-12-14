from Aspose.Pdf import SaveFormat
from Aspose.Pdf import HtmlLoadOptions
from Aspose.Pdf import Document
import clr

aspose_pdf = clr.AddReference("../../lib/Aspose.PDF.dll")

class html_to_pdf(object):
    def __init__(self, licence_path):
        self.dataDir = "../../TestData"
        if licence_path:
            self.licence_path = licence_path
            self.aspose_license = License()
            self.aspose_license.SetLicense(self.licence_path)

    def exec(self):
        pathSource1 = "../../TestData/test.html"
        pathSource2 = "../../TestData/Second/test.html"

        opt1 = HtmlLoadOptions
        # set html encoding
        opt1.InputEncoding = "UTF-8",
        # render all html to single large pdf page
        opt1.IsRenderToSinglePage = True

        # html files can be parsed and loaded as Aspose Document
        firstDoc = Document(pathSource1, opt1)

        opt2 = HtmlLoadOptions
        # set html encoding
        opt2.InputEncoding = "UTF-8",
        # split html content to pdf pages
        opt2.IsRenderToSinglePage = False

        secondDoc = Document(pathSource2, opt2)

        # create empty pdf document
        outputDoc = Document

        # set less memory usage with unload instead of fast performance
        outputDoc.EnableObjectUnload = True

        for page in firstDoc.Pages:
            # add page from one document to another directly
            outputDoc.Pages.Add(page)

        for page in secondDoc.Pages:
            # add page from one document to another directly
            outputDoc.Pages.Add(page)

        # save result pdf to file
        outputDoc.Save("test.pdf", SaveFormat.Pdf)
