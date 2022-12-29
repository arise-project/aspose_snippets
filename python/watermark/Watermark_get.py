from aspose.pdf import (
    WatermarkArtifact,
    Document
)


def get():
    
    pathSource = "../../TestData/test_with_watermark.pdf"
    doc = Document(pathSource)

    if(doc.Pages[1].Artifacts[1].Subtype == Aspose.Pdf.Artifact.ArtifactSubtype.Watermark)
        s = new FileStream("test.jpg",FileMode.Create)
        doc.Pages[1].Artifacts[1].Image.Save(fs)
        fs.Flush()