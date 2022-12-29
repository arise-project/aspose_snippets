import clr

aspose_pdf = clr.AddReference("../../lib/Aspose.PDF.dll")

from aspose.pdf import Document

class PDF(object):
    def __init__(self,licence_path):
        self.dataDir = "../../TestData"
        if licence_path:
            self.licence_path = licence_path
            self.aspose_license = License()
            self.aspose_license.SetLicense(self.licence_path)

    def exec():

        const string pathSource = "../../TestData/test.pdf";
            var pdfEditor = new PdfFileEditor();
            int beg = 1, end = 1;

            using (var fs = new FileStream(pathSource, FileMode.Open, FileAccess.Read))
            {
                using (var doc = new Document(fs))
                {
                    end = doc.Pages.Count;
                }
            }

            if(end > 1)
            {
                    end /= 2;
            }

            pdfEditor.Extract(pathSource, beg, end, "./half.pdf");