from Aspose.Pdf.DocSaveOptions import RecognitionMode
from Aspose.Pdf.DocSaveOptions import DocFormat
from Aspose.Pdf import DocSaveOptions
from Aspose.Pdf import Document
import clr

aspose_pdf = clr.AddReference("../../lib/Aspose.PDF.dll")

class pdf_to_doc(object):
    def __init__(self, licence_path):
        self.dataDir = "../../TestData"
        if licence_path:
            self.licence_path = licence_path
            self.aspose_license = License()
            self.aspose_license.SetLicense(self.licence_path)

    def exec(self):
        pathSource1 = "../../TestData/test.pdf"
        pathSource2 = "../../TestData/Second/test.pdf"

        # read pdf file to Aspose Document
        firstDoc = Document(pathSource1)
        secondDoc = Document(pathSource2)

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

        opt1 = DocSaveOptions
        # use doc format
        opt1.Format = DocFormat.Doc,
        # This mode is fast and good for maximally preserving original look
        opt1.Mode = RecognitionMode.Textbox

        # save pdf to Microsoft Word doc format
        outputDoc.Save("test.doc", opt1)
