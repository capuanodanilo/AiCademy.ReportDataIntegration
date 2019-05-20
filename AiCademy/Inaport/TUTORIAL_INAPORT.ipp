<ConfigBase className="com.inaplex.inaport.profile.IPProfileData">
  <version>7</version>
  <saved>20190517 10:29:33</saved>
  <nextTransform>
  </nextTransform>
  <runAnotherTransform>false</runAnotherTransform>
  <noChainOnError>false</noChainOnError>
  <chainIgnoreNoSrcFile>false</chainIgnoreNoSrcFile>
  <transactionLogging>false</transactionLogging>
  <commitRows>1</commitRows>
  <logFileWrite>false</logFileWrite>
  <logEventWrite>false</logEventWrite>
  <logFileName>Profile #P  #D.log</logFileName>
  <logFileAppend>true</logFileAppend>
  <logFileOp>4</logFileOp>
  <logEmailEnabled>false</logEmailEnabled>
  <logEmailTo>
  </logEmailTo>
  <logEmailFrom>
  </logEmailFrom>
  <logEmailCC>
  </logEmailCC>
  <logEmailSubject>Inaport Profile #P  #D#T</logEmailSubject>
  <logEmailAttachFile>false</logEmailAttachFile>
  <logEmailOp>1</logEmailOp>
  <prevFontFamily>Microsoft Sans Serif</prevFontFamily>
  <prevFontStyle>Regular</prevFontStyle>
  <prevFontSize>9</prevFontSize>
  <filters className="com.inaplex.inaport.profile.IPVector">
    <version>1</version>
    <saved>20190517 10:29:33</saved>
  </filters>
  <newFields className="com.inaplex.inaport.profile.IPVector">
    <version>1</version>
    <saved>20190517 10:29:33</saved>
    <element0 className="com.inaplex.inaport.profile.IPAddField">
      <version>1</version>
      <saved>20190517 10:29:33</saved>
      <name>NEW_COMPANYNAME</name>
      <initVal>''</initVal>
      <notes>LOOKUP - Company Name</notes>
    </element0>
    <element1 className="com.inaplex.inaport.profile.IPAddField">
      <version>1</version>
      <saved>20190517 10:29:33</saved>
      <name>NEW_GENDER</name>
      <initVal>''</initVal>
      <notes>OPTIONSET - Gender</notes>
    </element1>
    <element2 className="com.inaplex.inaport.profile.IPAddField">
      <version>1</version>
      <saved>20190517 10:29:33</saved>
      <name>NEW_CREDITHOLD</name>
      <initVal>''</initVal>
      <notes>BOOL - Credit Hold</notes>
    </element2>
  </newFields>
  <transforms className="com.inaplex.inaport.profile.IPVector">
    <version>1</version>
    <saved>20190517 10:29:33</saved>
    <element0 className="com.inaplex.inaport.profile.IPFieldTransform">
      <version>1</version>
      <saved>20190517 10:29:33</saved>
      <chkExpr>
      </chkExpr>
      <calcExpr>ltrim(rtrim(#[First Name]))</calcExpr>
      <targetFieldName>First Name</targetFieldName>
      <notes>string </notes>
    </element0>
    <element1 className="com.inaplex.inaport.profile.IPFieldTransform">
      <version>1</version>
      <saved>20190517 10:29:33</saved>
      <chkExpr>
      </chkExpr>
      <calcExpr>ltrim(rtrim(#[Last Name]))</calcExpr>
      <targetFieldName>Last Name</targetFieldName>
      <notes>string </notes>
    </element1>
    <element2 className="com.inaplex.inaport.profile.IPFieldTransform">
      <version>1</version>
      <saved>20190517 10:29:33</saved>
      <chkExpr>
      </chkExpr>
      <calcExpr>ltrim(rtrim(#Email))</calcExpr>
      <targetFieldName>Email</targetFieldName>
      <notes>string </notes>
    </element2>
    <element3 className="com.inaplex.inaport.profile.IPFieldTransform">
      <version>1</version>
      <saved>20190517 10:29:33</saved>
      <chkExpr>
      </chkExpr>
      <calcExpr>ltrim(rtrim(#[Business Phone]))</calcExpr>
      <targetFieldName>Business Phone</targetFieldName>
      <notes>string</notes>
    </element3>
    <element4 className="com.inaplex.inaport.profile.IPFieldTransform">
      <version>1</version>
      <saved>20190517 10:29:33</saved>
      <chkExpr>notblank(#Birthday)</chkExpr>
      <calcExpr>date(#Birthday,"dd/MM/yyyy")</calcExpr>
      <targetFieldName>Birthday</targetFieldName>
      <notes>DATE - Birthday</notes>
    </element4>
    <element5 className="com.inaplex.inaport.profile.IPFieldTransform">
      <version>1</version>
      <saved>20190517 10:29:33</saved>
      <chkExpr>isblank(#Birthday)</chkExpr>
      <calcExpr>'NULL_VALUE'</calcExpr>
      <targetFieldName>Birthday</targetFieldName>
      <notes>DATE - Birthday</notes>
    </element5>
    <element6 className="com.inaplex.inaport.profile.IPFieldTransform">
      <version>1</version>
      <saved>20190517 10:29:33</saved>
      <chkExpr>not(isnull(#[NEW_CREDITHOLD]))</chkExpr>
      <calcExpr>iif(#[NEW_CREDITHOLD] = "Si",1,0)</calcExpr>
      <targetFieldName>NEW_CREDITHOLD</targetFieldName>
      <notes>BOOL - Credit Hold</notes>
    </element6>
    <element7 className="com.inaplex.inaport.profile.IPFieldTransform">
      <version>1</version>
      <saved>20190517 10:29:33</saved>
      <chkExpr>#[NEW_GENDER] = 'Male'</chkExpr>
      <calcExpr>1</calcExpr>
      <targetFieldName>NEW_GENDER</targetFieldName>
      <notes>OPTIONSET - Gender</notes>
    </element7>
    <element8 className="com.inaplex.inaport.profile.IPFieldTransform">
      <version>1</version>
      <saved>20190517 10:29:33</saved>
      <chkExpr>#[NEW_GENDER] = 'Female'</chkExpr>
      <calcExpr>2</calcExpr>
      <targetFieldName>NEW_GENDER</targetFieldName>
      <notes>OPTIONSET - Gender</notes>
    </element8>
    <element9 className="com.inaplex.inaport.profile.IPFieldTransform">
      <version>1</version>
      <saved>20190517 10:29:33</saved>
      <chkExpr>
      </chkExpr>
      <calcExpr>iif(isnull(#[Company Name]),'NULL_VALUE',dbselect("T","SELECT accountid FROM account WHERE name ='#[Company Name]'")  + "::account") </calcExpr>
      <targetFieldName>NEW_COMPANYNAME</targetFieldName>
      <notes>LOOKUP - Company Name</notes>
    </element9>
    <element10 className="com.inaplex.inaport.profile.IPFieldTransform">
      <version>1</version>
      <saved>20190517 10:29:33</saved>
      <chkExpr>contains(#[NEW_COMPANYNAME], 'NULL_VALUE') </chkExpr>
      <calcExpr>'NULL_VALUE'</calcExpr>
      <targetFieldName>NEW_COMPANYNAME</targetFieldName>
      <notes>LOOKUP - Company Name</notes>
    </element10>
  </transforms>
  <rootNode className="com.inaplex.inaport.profile.IPTableNode">
    <version>1</version>
    <saved>20190517 10:29:33</saved>
    <nodeName>TableNode: contact</nodeName>
    <tblName>contact</tblName>
    <tableOp>60</tableOp>
    <errAct_NoMatch>10</errAct_NoMatch>
    <errAct_MultMatch>20</errAct_MultMatch>
    <errAct_DataErr>20</errAct_DataErr>
    <truncateFlds>false</truncateFlds>
    <skipNodeExpr>
    </skipNodeExpr>
    <logSkippedRecs>false</logSkippedRecs>
    <indexSetup className="com.inaplex.inaport.profile.IPTableIndexes">
      <version>1</version>
      <saved>20190517 10:29:33</saved>
      <matchType>10</matchType>
      <pkExpr>#contactid</pkExpr>
      <childKeyExpr>
      </childKeyExpr>
      <fkMap>Null object</fkMap>
      <userIndexes className="com.inaplex.inaport.profile.IPVector">
        <version>1</version>
        <saved>20190517 10:29:33</saved>
        <element0 className="com.inaplex.inaport.profile.IPVector">
          <version>1</version>
          <saved>20190517 10:29:33</saved>
          <element0 className="com.inaplex.inaport.profile.IPIndexMap">
            <version>1</version>
            <saved>20190517 10:29:33</saved>
            <srcExpr>#Email</srcExpr>
            <targExpr>#emailaddress1</targExpr>
            <notes>
            </notes>
          </element0>
        </element0>
      </userIndexes>
      <extMatchFileName>
      </extMatchFileName>
      <Sql>
      </Sql>
      <UseTargCon>true</UseTargCon>
      <fkSql>
      </fkSql>
      <clusterMap className="com.inaplex.inaport.profile.IPIndexMap">
        <version>1</version>
        <saved>20190517 10:29:33</saved>
        <srcExpr>
        </srcExpr>
        <targExpr>
        </targExpr>
        <notes>
        </notes>
      </clusterMap>
      <fuzzyMap className="com.inaplex.inaport.profile.IPIndexMap">
        <version>1</version>
        <saved>20190517 10:29:33</saved>
        <srcExpr>
        </srcExpr>
        <targExpr>
        </targExpr>
        <notes>
        </notes>
      </fuzzyMap>
      <fuzzyLower>85</fuzzyLower>
      <fuzzyUpper>95</fuzzyUpper>
      <fuzzyConfig className="com.inaplex.inaport.profile.IPFuzzyReviewConfig">
        <version>1</version>
        <saved>20190517 10:29:33</saved>
        <tables className="com.inaplex.utils.config.ConfigVector">
          <version>1</version>
          <saved>20190517 10:29:33</saved>
        </tables>
      </fuzzyConfig>
      <userReviewMode>30</userReviewMode>
    </indexSetup>
    <insertMap className="com.inaplex.inaport.profile.IPMapVec">
      <version>1</version>
      <saved>20190517 10:29:33</saved>
      <vec className="com.inaplex.inaport.profile.IPVector">
        <version>1</version>
        <saved>20190517 10:29:33</saved>
        <element0 className="com.inaplex.inaport.profile.IPMapPair">
          <version>1</version>
          <saved>20190517 10:29:33</saved>
          <srcExpr>
          </srcExpr>
          <inRecFldName>Birthday</inRecFldName>
          <outRecFldName>birthdate</outRecFldName>
          <mapFlags>1</mapFlags>
          <skipSrcBlank>false</skipSrcBlank>
          <skipTargNotBlank>false</skipTargNotBlank>
          <notes>
          </notes>
        </element0>
        <element1 className="com.inaplex.inaport.profile.IPMapPair">
          <version>1</version>
          <saved>20190517 10:29:33</saved>
          <srcExpr>
          </srcExpr>
          <inRecFldName>Business Phone</inRecFldName>
          <outRecFldName>assistantphone</outRecFldName>
          <mapFlags>1</mapFlags>
          <skipSrcBlank>false</skipSrcBlank>
          <skipTargNotBlank>false</skipTargNotBlank>
          <notes>
          </notes>
        </element1>
        <element2 className="com.inaplex.inaport.profile.IPMapPair">
          <version>1</version>
          <saved>20190517 10:29:33</saved>
          <srcExpr>
          </srcExpr>
          <inRecFldName>Last Name</inRecFldName>
          <outRecFldName>lastname</outRecFldName>
          <mapFlags>1</mapFlags>
          <skipSrcBlank>false</skipSrcBlank>
          <skipTargNotBlank>false</skipTargNotBlank>
          <notes>
          </notes>
        </element2>
        <element3 className="com.inaplex.inaport.profile.IPMapPair">
          <version>1</version>
          <saved>20190517 10:29:33</saved>
          <srcExpr>
          </srcExpr>
          <inRecFldName>Email</inRecFldName>
          <outRecFldName>emailaddress1</outRecFldName>
          <mapFlags>1</mapFlags>
          <skipSrcBlank>false</skipSrcBlank>
          <skipTargNotBlank>false</skipTargNotBlank>
          <notes>
          </notes>
        </element3>
        <element4 className="com.inaplex.inaport.profile.IPMapPair">
          <version>1</version>
          <saved>20190517 10:29:33</saved>
          <srcExpr>
          </srcExpr>
          <inRecFldName>First Name</inRecFldName>
          <outRecFldName>firstname</outRecFldName>
          <mapFlags>1</mapFlags>
          <skipSrcBlank>false</skipSrcBlank>
          <skipTargNotBlank>false</skipTargNotBlank>
          <notes>
          </notes>
        </element4>
        <element5 className="com.inaplex.inaport.profile.IPMapPair">
          <version>1</version>
          <saved>20190517 10:29:33</saved>
          <srcExpr>
          </srcExpr>
          <inRecFldName>NEW_COMPANYNAME</inRecFldName>
          <outRecFldName>parentcustomerid</outRecFldName>
          <mapFlags>1</mapFlags>
          <skipSrcBlank>false</skipSrcBlank>
          <skipTargNotBlank>false</skipTargNotBlank>
          <notes>
          </notes>
        </element5>
        <element6 className="com.inaplex.inaport.profile.IPMapPair">
          <version>1</version>
          <saved>20190517 10:29:33</saved>
          <srcExpr>
          </srcExpr>
          <inRecFldName>NEW_CREDITHOLD</inRecFldName>
          <outRecFldName>creditonhold</outRecFldName>
          <mapFlags>1</mapFlags>
          <skipSrcBlank>false</skipSrcBlank>
          <skipTargNotBlank>false</skipTargNotBlank>
          <notes>
          </notes>
        </element6>
        <element7 className="com.inaplex.inaport.profile.IPMapPair">
          <version>1</version>
          <saved>20190517 10:29:33</saved>
          <srcExpr>
          </srcExpr>
          <inRecFldName>NEW_GENDER</inRecFldName>
          <outRecFldName>gendercode</outRecFldName>
          <mapFlags>1</mapFlags>
          <skipSrcBlank>false</skipSrcBlank>
          <skipTargNotBlank>false</skipTargNotBlank>
          <notes>
          </notes>
        </element7>
      </vec>
    </insertMap>
    <updateMap>Null object</updateMap>
    <ownerSecCode>
    </ownerSecCode>
    <defaultUserId>
    </defaultUserId>
    <dispOwnerName>
    </dispOwnerName>
    <dispUserName>
    </dispUserName>
    <checkTargetDifferent>false</checkTargetDifferent>
    <isPKFldSQLIdentType>false</isPKFldSQLIdentType>
    <children className="com.inaplex.inaport.profile.IPVector">
      <version>1</version>
      <saved>20190517 10:29:33</saved>
    </children>
    <tableAlias>
    </tableAlias>
    <onSkippedExpr>
    </onSkippedExpr>
    <preExprVec className="com.inaplex.inaport.profile.IPVector">
      <version>1</version>
      <saved>20190517 10:29:33</saved>
    </preExprVec>
    <postExprVec className="com.inaplex.inaport.profile.IPVector">
      <version>1</version>
      <saved>20190517 10:29:33</saved>
    </postExprVec>
  </rootNode>
  <srcSQLString>
  </srcSQLString>
  <srcConnectorName>Connectors/TEST_CSV</srcConnectorName>
  <targConnectorName>Connectors/TEST.NUXUM.MSCRM</targConnectorName>
  <actTableName>
  </actTableName>
  <userNotes>
  </userNotes>
  <logExcluded>false</logExcluded>
  <logExcludedOp>1</logExcludedOp>
  <logExcludedConnectorType>2</logExcludedConnectorType>
  <logExcludedTableName>
  </logExcludedTableName>
  <logExcludedTablePKField>
  </logExcludedTablePKField>
  <logExcludedTablePKFieldIsIdent>false</logExcludedTablePKFieldIsIdent>
  <logExcludedTableActionClear>false</logExcludedTableActionClear>
  <logExcludedMap className="com.inaplex.inaport.profile.IPMapVec">
    <version>1</version>
    <saved>20190517 10:29:33</saved>
    <vec className="com.inaplex.inaport.profile.IPVector">
      <version>1</version>
      <saved>20190517 10:29:33</saved>
    </vec>
  </logExcludedMap>
  <onDataErrorExecExpr>
  </onDataErrorExecExpr>
  <preOpenExecExpr>
  </preOpenExecExpr>
  <preRunExecExpr>
  </preRunExecExpr>
  <postRunExecExpr>
  </postRunExecExpr>
  <postCloseExecExpr>
  </postCloseExecExpr>
</ConfigBase>