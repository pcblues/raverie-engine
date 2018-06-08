///////////////////////////////////////////////////////////////////////////////
///
/// Authors: Trevor Sundberg
/// Copyright 2016, DigiPen Institute of Technology
///
///////////////////////////////////////////////////////////////////////////////
#pragma once

namespace Zero
{
  /// Component to store the copyright info of a content item.
  class ContentCopyright : public ContentComponent
  {
  public:
    ZilchDeclareType(ContentCopyright, TypeCopyMode::ReferenceType);

    String Owner;
    String Date;

    void Serialize(Serializer& stream);
  };

  /// Stores the history in mercurial of this content item.
  class ContentHistory : public ContentComponent
  {
  public:
    ZilchDeclareType(ContentHistory, TypeCopyMode::ReferenceType);

    Array<Revision> mRevisions;

    void Initialize(ContentComposition* item);
  };

  /// Stores any user notes about the content item.
  class ContentNotes : public ContentComponent
  {
  public:
    ZilchDeclareType(ContentNotes, TypeCopyMode::ReferenceType);

    String Notes;

    void Serialize(Serializer& stream);
  };

  /// When added 
  class ResourceTemplate : public ContentComponent
  {
  public:
    ZilchDeclareType(ResourceTemplate, TypeCopyMode::ReferenceType);

    void Serialize(Serializer& stream);

    String mDisplayName;
    String mDescription;
    uint mSortWeight;
    String mCategory;
    uint mCategorySortWeight;
  };
}
