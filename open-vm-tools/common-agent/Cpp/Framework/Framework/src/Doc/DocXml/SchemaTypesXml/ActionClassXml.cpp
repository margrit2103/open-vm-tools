/*
 *  Author: bwilliams
 *  Created: April 6, 2012
 *
 *  Copyright (C) 2012-2016 VMware, Inc.  All rights reserved. -- VMware Confidential
 *
 *  This code was generated by the script "build/dev/codeGen/genCppXml". Please
 *  speak to Brian W. before modifying it by hand.
 *
 */

#include "stdafx.h"

#include "Doc/DocXml/SchemaTypesXml/MethodXml.h"

#include "Doc/SchemaTypesDoc/CActionClassDoc.h"
#include "Doc/SchemaTypesDoc/CCollectMethodDoc.h"
#include "Doc/SchemaTypesDoc/CMethodDoc.h"
#include "Xml/XmlUtils/CXmlElement.h"
#include "Doc/DocXml/SchemaTypesXml/ActionClassXml.h"
#include "Doc/DocXml/SchemaTypesXml/CollectMethodXml.h"

using namespace Caf;

void ActionClassXml::add(
	const SmartPtrCActionClassDoc actionClassDoc,
	const SmartPtrCXmlElement thisXml) {
	CAF_CM_STATIC_FUNC_VALIDATE("ActionClassXml", "add");

	CAF_CM_ENTER {
		CAF_CM_VALIDATE_SMARTPTR(actionClassDoc);
		CAF_CM_VALIDATE_SMARTPTR(thisXml);

		const std::string namespaceValVal = actionClassDoc->getNamespaceVal();
		CAF_CM_VALIDATE_STRING(namespaceValVal);
		thisXml->addAttribute("namespace", namespaceValVal);

		const std::string nameVal = actionClassDoc->getName();
		CAF_CM_VALIDATE_STRING(nameVal);
		thisXml->addAttribute("name", nameVal);

		const std::string versionVal = actionClassDoc->getVersion();
		CAF_CM_VALIDATE_STRING(versionVal);
		thisXml->addAttribute("version", versionVal);

		const SmartPtrCCollectMethodDoc collectMethodVal =
			actionClassDoc->getCollectMethod();
		if (! collectMethodVal.IsNull()) {
			const SmartPtrCXmlElement collectMethodXml =
				thisXml->createAndAddElement("collectMethod");
			CollectMethodXml::add(collectMethodVal, collectMethodXml);
		}

		const std::deque<SmartPtrCMethodDoc> methodVal =
			actionClassDoc->getMethodCollection();
		if (! methodVal.empty()) {
			for (TConstIterator<std::deque<SmartPtrCMethodDoc> > methodIter(methodVal);
				methodIter; methodIter++) {
				const SmartPtrCXmlElement methodXml =
					thisXml->createAndAddElement("method");
				MethodXml::add(*methodIter, methodXml);
			}
		}

		const std::string displayNameVal = actionClassDoc->getDisplayName();
		if (! displayNameVal.empty()) {
			thisXml->addAttribute("displayName", displayNameVal);
		}

		const std::string descriptionVal = actionClassDoc->getDescription();
		if (! descriptionVal.empty()) {
			thisXml->addAttribute("description", descriptionVal);
		}
	}
	CAF_CM_EXIT;
}

SmartPtrCActionClassDoc ActionClassXml::parse(
	const SmartPtrCXmlElement thisXml) {
	CAF_CM_STATIC_FUNC_VALIDATE("ActionClassXml", "parse");

	SmartPtrCActionClassDoc actionClassDoc;

	CAF_CM_ENTER {
		CAF_CM_VALIDATE_SMARTPTR(thisXml);

		const std::string namespaceValStrVal =
			thisXml->findRequiredAttribute("namespace");
		const std::string namespaceValVal = namespaceValStrVal;

		const std::string nameStrVal =
			thisXml->findRequiredAttribute("name");
		const std::string nameVal = nameStrVal;

		const std::string versionStrVal =
			thisXml->findRequiredAttribute("version");
		const std::string versionVal = versionStrVal;

		const SmartPtrCXmlElement collectMethodXml =
			thisXml->findOptionalChild("collectMethod");

		SmartPtrCCollectMethodDoc collectMethodVal;
		if (! collectMethodXml.IsNull()) {
			collectMethodVal = CollectMethodXml::parse(collectMethodXml);
		}

		const CXmlElement::SmartPtrCElementCollection methodChildrenXml =
			thisXml->findOptionalChildren("method");

		std::deque<SmartPtrCMethodDoc> methodVal;
		if (! methodChildrenXml.IsNull() && ! methodChildrenXml->empty()) {
			for (TConstIterator<CXmlElement::CElementCollection> methodXmlIter(*methodChildrenXml);
				methodXmlIter; methodXmlIter++) {
				const SmartPtrCXmlElement methodXml = methodXmlIter->second;
				const SmartPtrCMethodDoc methodDoc =
					MethodXml::parse(methodXml);
				methodVal.push_back(methodDoc);
			}
		}

		const std::string displayNameStrVal =
			thisXml->findOptionalAttribute("displayName");
		const std::string displayNameVal = displayNameStrVal;

		const std::string descriptionStrVal =
			thisXml->findOptionalAttribute("description");
		const std::string descriptionVal = descriptionStrVal;

		actionClassDoc.CreateInstance();
		actionClassDoc->initialize(
			namespaceValVal,
			nameVal,
			versionVal,
			collectMethodVal,
			methodVal,
			displayNameVal,
			descriptionVal);
	}
	CAF_CM_EXIT;

	return actionClassDoc;
}

