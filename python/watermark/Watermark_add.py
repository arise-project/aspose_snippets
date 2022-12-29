from aspose.pdf import (
    WatermarkArtifact,
    Document
)


def add():
    pathSource = "../../TestData/test.pdf"
    watermarkSource = "../../TestData/test.jpg"
    doc = Document(pathSource)

    artifact = WatermarkArtifact()
    artifact.SetImage(new FileStream(watermarkSource, FileMode.Open))

    artifact.ArtifactHorizontalAlignment = HorizontalAlignment.Center
    artifact.ArtifactVerticalAlignment = VerticalAlignment.Center
    artifact.Rotation = 15
    artifact.Opacity = 1
    artifact.IsBackground = True
    doc.Pages[1].Artifacts.Add(artifact)

    #save result pdf to file
    doc.Save("test.pdf", SaveFormat.PDF)
    