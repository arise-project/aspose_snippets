import clr

aspose_pdf = clr.AddReference("../../lib/Aspose.PDF.dll")

from aspose.pdf import Document

class get(object):
    def __init__(self,licence_path):
        self.dataDir = "../../TestData"
        if licence_path:
            self.licence_path = licence_path
            self.aspose_license = License()
            self.aspose_license.SetLicense(self.licence_path)

    def exec():

        const string pathSource = "../../TestData/test_with_watermark.pdf";
        var doc = new Aspose.Pdf.Document(pathSource);

        if(doc.Pages[1].Artifacts[1].Subtype == Aspose.Pdf.Artifact.ArtifactSubtype.Watermark)
        {
            using(var fs = new FileStream("test.jpg",FileMode.Create))
            {
                doc.Pages[1].Artifacts[1].Image.Save(fs);
                fs.Flush();
            }
        }