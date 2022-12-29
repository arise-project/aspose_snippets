import clr

aspose_pdf = clr.AddReference("../../lib/Aspose.PDF.dll")

from aspose.pdf import Document

class HTML(object):
    def __init__(self,licence_path):
        self.dataDir = "../../TestData"
        if licence_path:
            self.licence_path = licence_path
            self.aspose_license = License()
            self.aspose_license.SetLicense(self.licence_path)

    def exec():

        const string pathSource = "../../TestData/test.html";
            using (var doc = new Document(pathSource, new HtmlLoadOptions()))
            {
                //save input html to pdf to file
                doc.Save("test.pdf", SaveFormat.Pdf);
            }

            var pdfEditor = new PdfFileEditor();
            pdfEditor.SplitFromFirst("test.pdf", 1, "test.pdf");
            using (var doc = new Document("test.pdf"))
            {
                doc.Save("first_page.html", SaveFormat.Html);
            }