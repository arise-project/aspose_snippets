```python

doc = aspose.pdf.Document("1.pdf")

if doc.Pages[1].Artifacts[1].Subtype == aspose.pdf.ArtifactSubtype.Watermark:
	doc.Pages[1].Artifacts.Delete(doc.Pages[1].Artifacts[1])

#save result pdf to file
doc.Save("remove_watermark.pdf", aspose.pdf.SaveFormat.PDF)

```