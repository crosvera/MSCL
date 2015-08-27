NDSummary.OnToolTipsLoaded("File:MicroStrain/Wireless/Commands/PageDownload.h",{1252:"<div class=\"NDToolTip TClass LC\"><div class=\"NDClassPrototype\" id=\"NDClassPrototype1252\"><div class=\"CPEntry TClass Current\"><div class=\"CPName\">PageDownload</div></div></div><div class=\"TTSummary\">Contains logic for the PageDownload Node command</div></div>",1257:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype1257\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">static</span> ByteStream buildCommand(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\">NodeAddress&nbsp;</td><td class=\"PName last\">nodeAddress,</td></tr><tr><td class=\"PType first\"><span class=\"SHKeyword\">uint16</span>&nbsp;</td><td class=\"PName last\">pageIndex</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div><div class=\"TTSummary\">Builds the PageDownload command packet</div></div>",1258:"<div class=\"NDToolTip TClass LC\"><div class=\"NDClassPrototype\" id=\"NDClassPrototype1258\"><div class=\"CPEntry TClass Current\"><div class=\"CPName\">Response</div></div></div><div class=\"TTSummary\">Handles the response to the PageDownload Node command</div></div>",1260:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype1260\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\">Response(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PModifierQualifier first\">std::</td><td class=\"PType\">weak_ptr&lt;ResponseCollector&gt;&nbsp;</td><td class=\"PName last\">collector</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div><div class=\"TTSummary\">Creates a PageDownload Response object</div></div>",1262:"<div class=\"NDToolTip TVariable LC\"><div id=\"NDPrototype1262\" class=\"NDPrototype NoParameterForm\">ByteStream m_dataPoints</div><div class=\"TTSummary\">The data points that make up the &quot;page&quot; that was downloaded from the Node</div></div>",1263:"<div class=\"NDToolTip TVariable LC\"><div id=\"NDPrototype1263\" class=\"NDPrototype NoParameterForm\"><span class=\"SHKeyword\">bool</span> m_matchedPart1</div><div class=\"TTSummary\">Whether or not part 1 (the Command Byte) of the response has been matched</div></div>",1265:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype1265\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">virtual bool</span> match(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\">DataBuffer&nbsp;</td><td class=\"PNamePrefix\">&amp;</td><td class=\"PName last\">data</td></tr></table></td><td class=\"PAfterParameters\">) <span class=\"SHKeyword\">override</span></td></tr></table></div><div class=\"TTSummary\">Checks if the DataBuffer passed in matches the expected response pattern\'s bytes</div></div>",1266:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype1266\" class=\"NDPrototype NoParameterForm\">ByteStream dataPoints()</div><div class=\"TTSummary\">Gets the dataPoints that were downloaded from the Node</div></div>",1267:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype1267\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">bool</span> matchSuccessResponsePart1(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\">DataBuffer&nbsp;</td><td class=\"PNamePrefix\">&amp;</td><td class=\"PName last\">data</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div><div class=\"TTSummary\">Checks if the DataBuffer passed in matches the first part (Command Byte) of the response bytes</div></div>",1268:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype1268\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">bool</span> matchSuccessResponse(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\">DataBuffer&nbsp;</td><td class=\"PNamePrefix\">&amp;</td><td class=\"PName last\">data</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div><div class=\"TTSummary\">Checks if the DataBuffer passed in matches the success response bytes</div></div>",1269:"<div class=\"NDToolTip TFunction LC\"><div class=\"TTSummary\">Checks if the DataBuffer passed in matches the fail response bytes</div></div>"});