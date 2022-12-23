from Aspose.Pdf import Document

from Aspose.Pdf.DocSaveOptions import (
    RecognitionMode,
    DocFormat,
    DocSaveOptions
)

class pdf_to_docx(object):
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
        # use docx format
        opt1.Format = DocFormat.DocX,
        # make document editable flow and recognize of tables
        opt1.Mode = RecognitionMode.EnhancedFlow

        # save pdf to Microsoft Word docx format
        outputDoc.Save("test.docx", opt1)
