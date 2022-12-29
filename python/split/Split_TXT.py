import clr

aspose_pdf = clr.AddReference("../../lib/Aspose.PDF.dll")

from aspose.pdf import Document

class TXT(object):
    def __init__(self,licence_path):
        self.dataDir = "../../TestData"
        if licence_path:
            self.licence_path = licence_path
            self.aspose_license = License()
            self.aspose_license.SetLicense(self.licence_path)

    def exec():
        const string pathSource = "../../TestData/test.txt";
        var pdfEditor = new PdfFileEditor();

        var doc = new Document(pathSource, new TxtLoadOptions());
        //save input text to pdf to file
        doc.Save("test.pdf", SaveFormat.Pdf);

        MemoryStream [] pages = pdfEditor.SplitToPages("test.pdf");
        int index = 1;
        foreach(var ms in pages)
        {
            var page = new Document(ms);
            var textAbsorber = new TextAbsorber();
            page.Pages.Accept(textAbsorber);
            string extractedText = textAbsorber.Text;
            File.WriteAllText("text_"+index+".txt", extractedText);
            index++;
        }
        