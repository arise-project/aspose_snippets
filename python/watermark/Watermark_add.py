from aspose.pdf import (
    WatermarkArtifact,
    HorizontalAlignment,
    VerticalAlignment,
    Document,
    SaveFormat
)


def add():
    path_source = "../../TestData/test.pdf"
    watermark_source = "../../TestData/test.jpg"
    doc = Document(path_source)

    artifact = WatermarkArtifact()
    artifact.SetImage(watermark_source)

    artifact.ArtifactHorizontalAlignment = HorizontalAlignment.Center
    artifact.ArtifactVerticalAlignment = VerticalAlignment.Center
    artifact.Rotation = 15
    artifact.Opacity = 1
    artifact.IsBackground = True
    doc.Pages[1].Artifacts.Add(artifact)

    #save result pdf to file
    doc.Save("add_watermark.pdf", SaveFormat.PDF)
    