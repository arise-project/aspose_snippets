import clr

aspose_pdf = clr.AddReference("../../lib/Aspose.PDF.dll")

from Aspose.Pdf import Document

class pdf_to_pptx(object):
    def __init__(self,licence_path):
        self.dataDir = "../../TestData"
        if licence_path:
            self.licence_path = licence_path
            self.aspose_license = License()
            self.aspose_license.SetLicense(self.licence_path)

    def exec(self):

        pathSource1 = "../../TestData/test.pdf"
        pathSource2 = "../../TestData/Second/test.pdf"

        #read pdf file to Aspose Document
        firstDoc = Document(pathSource1)
        secondDoc = Document(pathSource2)

        outputDoc = new Aspose.Pdf.Document
        #set less memory usage with unload instead of fast performance
        outputDoc.EnableObjectUnload = true
        
        for page in firstDoc.Pages:
            # add page from one document to another directly
            outputDoc.Pages.Add(page)

        for page in secondDoc.Pages:
            # add page from one document to another directly
            outputDoc.Pages.Add(page)

        opt1 = new Aspose.Pdf.PptxSaveOptions
        #save all content on page as single image
        opt1.SlidesAsImages = true      

        #save pdf to Microsoft PowerPoint
        outputDoc.Save("test.pptx", opt1)
