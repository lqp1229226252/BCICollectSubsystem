-- MySQL dump 10.13  Distrib 5.7.39, for Linux (x86_64)
--
-- Host: localhost    Database: WGB
-- ------------------------------------------------------
-- Server version	5.7.39-0ubuntu0.18.04.2

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `account`
--

DROP TABLE IF EXISTS `account`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `account` (
  `account` varchar(11) NOT NULL COMMENT '账号',
  `password` varchar(16)  NOT NULL COMMENT '密码',
  `id` int(11) NOT NULL COMMENT '用户的编号',
  PRIMARY KEY (`account`),
  UNIQUE KEY `account_UNIQUE` (`account`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `account`
--

LOCK TABLES `account` WRITE;
/*!40000 ALTER TABLE `account` DISABLE KEYS */;
INSERT INTO `account` VALUES ('123456','123456',1);
/*!40000 ALTER TABLE `account` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `conacts`
--

DROP TABLE IF EXISTS `conacts`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `conacts` (
  `id` int(11) NOT NULL COMMENT '用户的编号',
  `name` varchar(10) NOT NULL COMMENT '联系人的名字',
  `phone` varchar(11) NOT NULL COMMENT '联系人的电话',
  `address` varchar(20) NOT NULL COMMENT '联系人的地址'
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `conacts`
--

LOCK TABLES `conacts` WRITE;
/*!40000 ALTER TABLE `conacts` DISABLE KEYS */;
/*!40000 ALTER TABLE `conacts` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `user`
--

DROP TABLE IF EXISTS `user`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `user` (
  `id` int(10) unsigned zerofill NOT NULL COMMENT '用户的编号',
  `user_name` varchar(6) NOT NULL COMMENT '用户昵称',
  `name` varchar(10) DEFAULT NULL COMMENT '用户的名字',
  `age` int(10) unsigned NOT NULL DEFAULT '18' COMMENT '用户年龄',
  `nation` varchar(10)  DEFAULT NULL COMMENT '民族',
  `sex` tinyint(4) DEFAULT NULL COMMENT '用户的性别(0 女,1 男)',
  `handedness` tinyint(4) DEFAULT NULL COMMENT '左右利手(0 右,1 左)',
  `work_exp` tinytext COMMENT '工作经验',
  `edu_level` tinytext COMMENT '教育水平',
  `phone` varchar(11) DEFAULT NULL COMMENT '联系电话',
  `address` varchar(20) DEFAULT NULL COMMENT '用户地址',
  `contact_way` varchar(10) DEFAULT NULL COMMENT '联系方式',
  `exercising_way` varchar(20) DEFAULT NULL COMMENT '锻炼方式',
  `health` tinyint(4) DEFAULT NULL COMMENT '身体状况(0 生病，1 健康)\n',
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `user`
--

LOCK TABLES `user` WRITE;
/*!40000 ALTER TABLE `user` DISABLE KEYS */;
/*!40000 ALTER TABLE `user` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2022-10-21  5:03:03
