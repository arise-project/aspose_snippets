import clr

aspose_pdf = clr.AddReference("../../lib/Aspose.PDF.dll")

from aspose.pdf import Document

class add(object):
    def __init__(self,licence_path):
        self.dataDir = "../../TestData"
        if licence_path:
            self.licence_path = licence_path
            self.aspose_license = License()
            self.aspose_license.SetLicense(self.licence_path)

    def exec():

        const string pathSource = "../../TestData/test.pdf";
            const string watermarkSource = "../../TestData/test.jpg";
            var doc = new Aspose.Pdf.Document(pathSource);

            var artifact = new Aspose.Pdf.WatermarkArtifact();
            artifact.SetImage(new FileStream(watermarkSource, FileMode.Open));

            artifact.ArtifactHorizontalAlignment = Aspose.Pdf.HorizontalAlignment.Center;
            artifact.ArtifactVerticalAlignment = Aspose.Pdf.VerticalAlignment.Center;
            artifact.Rotation = 15;
            artifact.Opacity = 1;
            artifact.IsBackground = true;
            doc.Pages[1].Artifacts.Add(artifact);

            //save result pdf to file
            doc.Save("test.pdf", Aspose.Pdf.SaveFormat.Pdf);