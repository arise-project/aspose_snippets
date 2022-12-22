import clr

aspose_pdf = clr.AddReference("../../lib/Aspose.PDF.dll")

from Aspose.Pdf import Document
from Aspose.Pdf import PsLoadOptions
from Aspose.Pdf import SaveFormat

class ps_to_pdf(object):
    def __init__(self,licence_path):
        self.dataDir = "../../TestData"
        if licence_path:
            self.licence_path = licence_path
            self.aspose_license = License()
            self.aspose_license.SetLicense(self.licence_path)

    def exec(self):

        pathSource1 = "../../TestData/test.ps"
        pathSource2 = "../../TestData/Second/test.ps"

        #PostScript files can be parsed and loaded as Aspose Document
        firstDoc = Document(pathSource1, PsLoadOptions)
        secondDoc = Document(pathSource2, PsLoadOptions)

        #create empty pdf document
        outputDoc = Document

        #set less memory usage with unload instead of fast performance
        outputDoc.EnableObjectUnload = True

        for page in firstDoc.Pages:
            #add page from one document to another directly
            outputDoc.Pages.Add(page)

        for page in secondDoc.Pages:
            #add page from one document to another directly
            outputDoc.Pages.Add(page)

        #save result pdf to file
        outputDoc.Save("test.pdf", SaveFormat.Pdf)