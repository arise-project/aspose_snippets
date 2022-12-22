import clr

aspose_pdf = clr.AddReference("../../lib/Aspose.PDF.dll")

from Aspose.Pdf import Document

class xps_to_pdf(object):
    def __init__(self,licence_path):
        self.dataDir = "../../TestData"
        if licence_path:
            self.licence_path = licence_path
            self.aspose_license = License()
            self.aspose_license.SetLicense(self.licence_path)

    def exec(self):

        var pathSource1 = "../../TestData/test.xps";
            var pathSource2 = "../../TestData/Second/test.xps";

            //xps files can be parsed and loaded as Aspose Document
            var firstDoc = new Aspose.Pdf.Document(pathSource1, new Aspose.Pdf.XpsLoadOptions());
            var secondDoc = new Aspose.Pdf.Document(pathSource2, new Aspose.Pdf.XpsLoadOptions());

            //create empty pdf document
            var outputDoc = new Aspose.Pdf.Document();

            //set less memory usage with unload instead of fast performance
            outputDoc.EnableObjectUnload = true;

            foreach (var page in firstDoc.Pages)
            {
                //add page from one document to another directly
                outputDoc.Pages.Add(page);
            }

            foreach (var page in secondDoc.Pages)
            {
                //add page from one document to another directly
                outputDoc.Pages.Add(page);
            }

            //save result pdf to file
            outputDoc.Save("test.pdf", Aspose.Pdf.SaveFormat.Pdf);