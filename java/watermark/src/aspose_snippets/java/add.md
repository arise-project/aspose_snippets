```java

doc = new com.aspose.pdf.Document("1.pdf");

artifact = new com.aspose.pdf.WatermarkArtifact();
artifact.setImage("1.jpg");

artifact.setArtifactHorizontalAlignment(com.aspose.pdf.HorizontalAlignment.Center);
artifact.setArtifactVerticalAlignment(com.aspose.pdf.VerticalAlignment.Center);
artifact.setRotation(15);
artifact.setOpacity(1);
artifact.setBackground(true);
doc.getPages().get_Item(1).getArtifacts().add(artifact);

//save result pdf to file
doc.save("add_watermark.pdf", com.aspose.pdf.SaveFormat.Pdf);

```