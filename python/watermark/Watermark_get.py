from aspose.pdf import (
    WatermarkArtifact,
    Artifact,
    Document
)


def get():
    
    path_source = "../../TestData/test_with_watermark.pdf"
    doc = Document(path_source)

    if doc.Pages[1].Artifacts[1].Subtype == Artifact.ArtifactSubtype.Watermark:
        fs = open("test.jpg", 'w')
        doc.Pages[1].Artifacts[1].Image.Save(fs)
        fs.flush()
        fs.close();